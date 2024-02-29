#include "DualMLP.hpp"

DualMLP::DualMLP(unsigned inputCount, unsigned hiddenNodeCount, unsigned outputCount, NodeClass nodeClass, bool zeroed)
:   m_firstHiddenLayer  (inputCount, hiddenNodeCount, nodeClass, zeroed),
    m_secondHiddenLayer (hiddenNodeCount, hiddenNodeCount, nodeClass, zeroed),
    m_outputLayer       (hiddenNodeCount, outputCount, nodeClass, zeroed)
{
    m_inputCount = inputCount;
    m_hiddenNodeCount = hiddenNodeCount;
    m_outputCount = outputCount;
    m_nodeClass = nodeClass;
}

void DualMLP::setChromosome(const Chromosome &chromosome)
{
    if (chromosome.size() != getChromosomeSize())
    {
        return;
    }

    auto l1 = chromosome.begin() + m_firstHiddenLayer.getChromosomeSize();
    auto l2 = l1 + m_secondHiddenLayer.getChromosomeSize();

    Chromosome chr1(chromosome.begin(), l1);
    Chromosome chr2(l1, l2);
    Chromosome chr3(l2, chromosome.end());

    m_firstHiddenLayer.setChromosome(chr1);
    m_secondHiddenLayer.setChromosome(chr2);
    m_outputLayer.setChromosome(chr3);
}

Chromosome DualMLP::getChromosome() const
{
    Chromosome chromosome;

    Chromosome chr1 = m_firstHiddenLayer.getChromosome();
    Chromosome chr2 = m_secondHiddenLayer.getChromosome();
    Chromosome chr3 = m_outputLayer.getChromosome();

    chromosome.insert(chromosome.end(), chr1.begin(), chr1.end());
    chromosome.insert(chromosome.end(), chr2.begin(), chr2.end());
    chromosome.insert(chromosome.end(), chr3.begin(), chr3.end());

    return chromosome;
}

unsigned DualMLP::getChromosomeSize() const
{
    unsigned chrSize = 0;
    chrSize += m_firstHiddenLayer.getChromosomeSize();
    chrSize += m_secondHiddenLayer.getChromosomeSize();
    chrSize += m_outputLayer.getChromosomeSize();

    return chrSize;
}

std::vector<float> DualMLP::io(const std::vector<float> &inputs)
{
    std::vector<float> response;

    if (inputs.size() != m_inputCount)
    {
        return response;
    }

    response = m_firstHiddenLayer.io(inputs);
    response = m_secondHiddenLayer.io(response);
    response = m_outputLayer.io(response);

    return response;
}
