#include "Population.hpp"

Population::Population(unsigned popSize, unsigned eliteCount, unsigned chromosomeSize)
:   m_popSize(popSize), m_eliteCount(eliteCount), m_chromosomeSize(chromosomeSize)
{
    m_fitnesses.resize(m_popSize, 0.f);
    m_chromosomes.resize(m_popSize);
    for (auto &i : m_chromosomes)
    {
        i.resize(m_chromosomeSize, 0.f);
        for (auto &j : i)
        {
            j = realRand(-1.f, 1.f);
        }
    }
}

void Population::roulleteWheel()
{
    std::vector<Chromosome> newGeneration;

    std::vector<unsigned> eliteIndexes(m_eliteCount, 0);
    for (auto &i : eliteIndexes)
    {
        for (unsigned j = 0; j < m_popSize; ++j)
        {
            bool picked = false;
            for (auto &k : eliteIndexes)
            {
                if (k == j)
                {
                    picked = true;
                    break;
                }
            }
            if (picked)
            {
                continue;
            }
            if (m_fitnesses[j] > m_fitnesses[i])
            {
                i = j;
            }
        }
    }

    for (auto &i : eliteIndexes)
    {
        newGeneration.push_back(m_chromosomes[i]);
    }

    unsigned fitnessSum = 0;
    for (auto &i : m_fitnesses)
    {
        fitnessSum += i;
    }

    for (unsigned i = m_eliteCount; i < m_popSize; i += 2)
    {
        unsigned parentIndex = 0;
        unsigned motherIndex = 0;
        int randomParent = intRand(0, fitnessSum);
        int randomMother = intRand(0, fitnessSum);

        while (randomParent > 0)
        {
            randomParent -= m_fitnesses[parentIndex];
            ++parentIndex;
        }   --parentIndex;

        while (randomMother > 0)
        {
            randomMother -= m_fitnesses[motherIndex];
            ++motherIndex;
        }   --motherIndex;

        Chromosome child1;
        Chromosome child2;

        crossover(m_chromosomes[parentIndex], m_chromosomes[motherIndex], child1, child2);
        mutate(child1);
        mutate(child2);

        newGeneration.push_back(child1);
        newGeneration.push_back(child2);
    }

    if (newGeneration.size() < m_chromosomes.size())
    {
        newGeneration.push_back(newGeneration.back());
    }

    m_chromosomes = newGeneration;
    m_fitnesses = std::vector<unsigned>(m_popSize, 0);
}
