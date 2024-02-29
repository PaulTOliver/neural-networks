#include "SingleMLP.hpp"

SingleMLP::SingleMLP(unsigned inputCount, unsigned hiddenNodeCount, unsigned outputCount, NodeClass nodeClass, bool zeroed)
:   m_hiddenLayer(inputCount, hiddenNodeCount, nodeClass, zeroed),
    m_outputLayer(hiddenNodeCount, outputCount, nodeClass, zeroed)
{
    m_inputCount = inputCount;
    m_hiddenNodeCount = hiddenNodeCount;
    m_outputCount = outputCount;
    m_nodeClass = nodeClass;
}

void SingleMLP::setChromosome(const Chromosome &chromosome)
{
    if (chromosome.size() != getChromosomeSize())
    {
        return;
    }

    auto l1 = chromosome.begin() + m_hiddenLayer.getChromosomeSize();

    Chromosome chr1(chromosome.begin(), l1);
    Chromosome chr2(l1, chromosome.end());

    m_hiddenLayer.setChromosome(chr1);
    m_outputLayer.setChromosome(chr2);
}

Chromosome SingleMLP::getChromosome() const
{
    Chromosome chromosome;

    Chromosome chr1 = m_hiddenLayer.getChromosome();
    Chromosome chr2 = m_outputLayer.getChromosome();

    chromosome.insert(chromosome.end(), chr1.begin(), chr1.end());
    chromosome.insert(chromosome.end(), chr2.begin(), chr2.end());

    return chromosome;
}

unsigned SingleMLP::getChromosomeSize() const
{
    unsigned chrSize = 0;
    chrSize += m_hiddenLayer.getChromosomeSize();
    chrSize += m_outputLayer.getChromosomeSize();

    return chrSize;
}

std::vector<float> SingleMLP::io(const std::vector<float> &inputs)
{
    std::vector<float> response;

    if (inputs.size() != m_inputCount)
    {
        return response;
    }

    response = m_hiddenLayer.io(inputs);
    response = m_outputLayer.io(response);

    return response;
}
