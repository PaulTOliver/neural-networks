#ifndef __POPULATION_HPP__
#define __POPULATION_HPP__

#include "NNUtils.hpp"

class Population
{
public:
    Population(unsigned popSize, unsigned eliteCount, unsigned chromosomeSize);

    void roulleteWheel();

    unsigned getPopSize() const { return m_popSize; }
    unsigned getChromosomeSize() const { return m_chromosomeSize; }
    unsigned getEliteCount() const { return m_eliteCount; }

    void setFitness(unsigned i, unsigned fitness) { m_fitnesses[i] = fitness; }
    Chromosome getChromosome(unsigned i) const { return m_chromosomes[i]; }
    unsigned getFitness(unsigned i) const { return m_fitnesses[i]; }

private:
    unsigned m_popSize = 0;
    unsigned m_eliteCount = 0;
    unsigned m_chromosomeSize = 0;

    std::vector<Chromosome> m_chromosomes;
    std::vector<unsigned> m_fitnesses;
};

#endif // __POPULATION_HPP__
