#include "MemCell.hpp"

MemCell::MemCell(unsigned inputCount, bool zeroed)
:   m_input     (inputCount, zeroed),
    m_inputGate (inputCount + 1, zeroed),
    m_memGate   (inputCount + 1, zeroed),
    m_outputGate(inputCount + 1, zeroed)
{
    m_inputCount = inputCount;
}

void MemCell::setChromosome(const Chromosome &chromosome)
{
    unsigned chrSize = getChromosomeSize();

    if (chromosome.size() != chrSize)
    {
        return;
    }

    auto l1 = chromosome.begin() + m_input.getChromosomeSize();
    auto l2 = l1 + m_inputGate.getChromosomeSize();
    auto l3 = l2 + m_memGate.getChromosomeSize();

    Chromosome chrInput(chromosome.begin(), l1);
    Chromosome chrInputGate(l1, l2);
    Chromosome chrMemGate(l2, l3);
    Chromosome chrOutputGate(l3, chromosome.end());

    m_input.setChromosome(chrInput);
    m_inputGate.setChromosome(chrInputGate);
    m_memGate.setChromosome(chrMemGate);
    m_outputGate.setChromosome(chrOutputGate);
}

Chromosome MemCell::getChromosome() const
{
    Chromosome chromosome;

    Chromosome chrInput = m_input.getChromosome();
    Chromosome chrInputGate = m_inputGate.getChromosome();
    Chromosome chrMemGate = m_memGate.getChromosome();
    Chromosome chrOutputGate = m_outputGate.getChromosome();

    chromosome.insert(chromosome.end(), chrInput.begin(), chrInput.end());
    chromosome.insert(chromosome.end(), chrInputGate.begin(), chrInputGate.end());
    chromosome.insert(chromosome.end(), chrMemGate.begin(), chrMemGate.end());
    chromosome.insert(chromosome.end(), chrOutputGate.begin(), chrOutputGate.end());

    return chromosome;
}

unsigned MemCell::getChromosomeSize() const
{
    unsigned chrSize = 0;

    chrSize += m_input.getChromosomeSize();
    chrSize += m_inputGate.getChromosomeSize();
    chrSize += m_memGate.getChromosomeSize();
    chrSize += m_outputGate.getChromosomeSize();

    return chrSize;
}

float MemCell::io(const std::vector<float> &inputs)
{
    float response = 0.f;

    if (inputs.size() != m_inputCount)
    {
        return response;
    }

    std::vector<float> gateInputs = inputs;
    gateInputs.push_back(m_context);

    response = m_input.io(inputs) * m_inputGate.io(gateInputs);
    float memory = m_context * m_memGate.io(gateInputs);
    m_context = memory + response;

    response = sigmoid(m_context) * m_outputGate.io(gateInputs);
    return response;
}
