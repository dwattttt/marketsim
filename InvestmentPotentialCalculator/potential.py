from pyevolve import G1DList
from pyevolve import GSimpleGA
from pyevolve import Statistics
 
def readDataFile(dataPath):
    f = open(dataPath, 'r')
    lines = f.readlines()
    lines = [list(map(float, line.strip().split(','))) for line in lines]
    return lines
    
class Market:
    def __init__(self, data):
        self.wealth = 10.0

        self.data = data[:]
        (self.price1, self.price2) = self.data.pop(0)
        self.steps = len(self.data)

    def step(self, allocation):
        assert (allocation >= 0.0)
        assert (allocation <= 1.0)
        
        shares2 = 0.0
        if allocation != 1.0:
            shares2 = self.wealth/(self.price1 * (allocation/(1.0-allocation)) + self.price2)
        shares1 = (self.wealth - shares2*self.price2)/self.price1

        (self.price1, self.price2) = self.data.pop(0)
        self.wealth = shares1*self.price1 + shares2*self.price2

        return self.wealth


def wealth_possible(chromosome):
    m = Market(DATA_TEMPLATE)
    for value in chromosome:
        score = m.step(value / 20.0)

    return score

def eval_func(chromosome):
    m = Market(DATA_TEMPLATE)

    #the solidarity bonus is an attempt to get the population to stick
    #with one allocation for as long as possible, it's on a complete tangent
    #with getting rich though, so it seems that it's one or the other...
    lastValue = -1
    solidarityStep = 0.5
    solidarityBonus = 0.0
    solidarityBonusTotal = 0.0
    for value in chromosome:
        allocation = value / 20.0
        score = m.step(allocation)

        if lastValue == value:
            solidarityBonus += solidarityStep
            solidarityBonusTotal += solidarityBonus
        else:
            solidarityBonus = 0.0
            
        lastValue = value

    return score + solidarityBonusTotal

DATA_TEMPLATE = readDataFile('data.dat')

if __name__ == '__main__':
    m = Market(DATA_TEMPLATE)

    genome = G1DList.G1DList(m.steps)
    genome.evaluator.set(eval_func)
    genome.setParams(rangemin=0, rangemax=20)
    
    ga = GSimpleGA.GSimpleGA(genome)
    ga.setGenerations(1000)
    ga.setPopulationSize(m.steps / 2)
    
    # Do the evolution, with stats dump
    # frequency of 10 generations
    ga.evolve(freq_stats=50)

    pop = ga.getPopulation()
    stats = pop.getStatistics()

    print ''
    print 'Optimal possible "wealth": ' + str(wealth_possible(ga.bestIndividual()))
    print 'Allocations chart:'
    allocations = [val * 5 for val in ga.bestIndividual()]
    userFriendly = []
    for i in range(1,len(allocations)):
        if allocations[i-1] == allocations[i]:
            userFriendly.append('K')
        else:
            userFriendly.append(allocations[i])
    print userFriendly
    
