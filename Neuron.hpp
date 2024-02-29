#ifndef __NEURON_HPP__
#define __NEURON_HPP__

#include "Node.hpp"

class Neuron : public Node
{
public:
    Neuron(unsigned inputCount, bool zeroed = false);

    void setChromosome(const Chromosome &chromosome);
    Chromosome getChromosome() const;
    unsigned getChromosomeSize() const { return m_inputCount + 1; }

    float io(const std::vector<float> &inputs);

private:
    std::vector<float> m_weights;
    float m_bias = 0.f;
};

#endif // __NEURON_HPP__
