#ifndef __NEURALNET_HPP__
#define __NEURALNET_HPP__

#include "NodeLayer.hpp"

class NeuralNet
{
public:
    virtual void setChromosome(const Chromosome &chromosome) = 0;
    virtual Chromosome getChromosome() const = 0;
    virtual unsigned getChromosomeSize() const = 0;

    virtual std::vector<float> io(const std::vector<float> &inputs) = 0;

    unsigned getInputCount() const { return m_inputCount; }
    unsigned getHiddenNodeCount() const { return m_hiddenNodeCount; }
    unsigned getOutputCount() const { return m_outputCount; }

protected:
    unsigned m_inputCount = 0;
    unsigned m_hiddenNodeCount = 0;
    unsigned m_outputCount = 0;
    NodeClass m_nodeClass;
};

#endif // __NEURALNET_HPP__
