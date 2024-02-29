#include "Neuron.hpp"

Neuron::Neuron(unsigned inputCount, bool zeroed)
{
    m_inputCount = inputCount;

    while (inputCount--)
    {
        m_weights.push_back(zeroed ? 0.f : realRand(-1.f, 1.f));
    }

    m_bias = zeroed ? 0.f : realRand(-1.f, 1.f);
}

void Neuron::setChromosome(const Chromosome &chromosome)
{
    unsigned chrSize = getChromosomeSize();

    if (chrSize != chromosome.size())
    {
        return;
    }

    m_weights = Chromosome(chromosome.begin(), chromosome.end() - 1);
    m_bias = chromosome.back();
}

Chromosome Neuron::getChromosome() const
{
    Chromosome chromosome;

    for (auto &i : m_weights)
    {
        chromosome.push_back(i);
    }

    chromosome.push_back(m_bias);

    return chromosome;
}

float Neuron::io(const std::vector<float> &inputs)
{
    float response = 0.f;

    if (inputs.size() != m_inputCount)
    {
        return response;
    }

    for (unsigned i = 0; i < m_inputCount; ++i)
    {
        response += inputs[i] * m_weights[i];
    }

    return sigmoid(response - m_bias);
}
