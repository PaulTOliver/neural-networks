#ifndef __MEMCELL_HPP__
#define __MEMCELL_HPP__

#include "Neuron.hpp"

class MemCell : public Node
{
public:
    MemCell(unsigned inputCount, bool zeroed = false);

    void setChromosome(const Chromosome &chromosome);
    Chromosome getChromosome() const;
    unsigned getChromosomeSize() const;

    float io(const std::vector<float> &inputs);

private:
    Neuron m_input;
    Neuron m_inputGate;
    Neuron m_memGate;
    Neuron m_outputGate;

    float m_context = 0.f;
};

#endif // __MEMCELL_HPP__
