from pyevolve import G1DList
from pyevolve import GSimpleGA
from pyevolve import Statistics
from pyevolve import Selectors
 
def readDataFile(dataPath):
    f = open(dataPath, 'r')
    lines = f.readlines()
    lines = [list(map(float, line.strip().split(','))) for line in lines]
    return lines

def dummy(data):
    pass

class Market:
    def __init__(self, data):
        self.wealth = 10.0
        self.subFn = dummy
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

    def sub(self, fn):
        self.subFn = fn


def wealth_possible(chromosome):
    m = Market(DATA_TEMPLATE)
    for value in chromosome:
        for i in range(0,STEP_SIZE):
            score = m.step(value)

    return score

def five_minute_potential(chromosome, time=5):
    m = Market(DATA_TEMPLATE)
    for i in range(0,(60/(STEP_SIZE*2)*time)):
        for j in range(0, STEP_SIZE):
            print m.step(ga.bestIndividual()[i])

def eval_func(chromosome):
    m = Market(DATA_TEMPLATE)

    #the penalty is an attempt to get the population to stick
    #with one allocation for as long as possible, it's on a complete tangent
    #with getting rich though, so it seems that it's one or the other...
    lastValue = -1
    changePenalty = 0.1
    penaltyTotal = 0.0
    for value in chromosome:
        allocation = value / 1.0
        for i in range(0,STEP_SIZE):
            score = m.step(allocation)

        if lastValue != value:
            penaltyTotal += 1.5

        lastValue = value

    return score * max(0,(1.0 - (penaltyTotal / len(chromosome))))

DATA_TEMPLATE = readDataFile('data.dat')
STEP_SIZE = 5

if __name__ == '__main__':
    m = Market(DATA_TEMPLATE)

    genome = G1DList.G1DList(m.steps / STEP_SIZE)
    genome.evaluator.set(eval_func)
    genome.setParams(rangemin=0, rangemax=1)
    
    ga = GSimpleGA.GSimpleGA(genome)
    ga.setGenerations(10000)
    ga.setPopulationSize(2 * m.steps / STEP_SIZE)
    ga.terminationCriteria.set(GSimpleGA.ConvergenceCriteria)
    ga.setMutationRate(0.04)
    
    # Do the evolution, with stats dump
    # frequency of 10 generations
    ga.evolve(freq_stats=50)

    pop = ga.getPopulation()
    stats = pop.getStatistics()

    print ''
    print 'Optimal possible "wealth": ' + str(wealth_possible(ga.bestIndividual()))
    print 'Allocations chart:'
    allocations = [val * 100 for val in ga.bestIndividual()]
    print allocations

    lastValue = -1
    for i in range(0,m.steps / STEP_SIZE):
        time = 1200 - i * STEP_SIZE * 2
        mins = int(time / 60)
        secs = time % 60

        if ga.bestIndividual()[i] != lastValue:
            lastValue = ga.bestIndividual()[i]
            print "{0:02d}:{1:02d} - {2}".format(mins,secs,ga.bestIndividual()[i])
