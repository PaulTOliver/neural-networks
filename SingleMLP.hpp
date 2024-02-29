#ifndef __SINGLEMLP_HPP__
#define __SINGLEMLP_HPP__

#include "NeuralNet.hpp"

class SingleMLP : public NeuralNet
{
public:
    SingleMLP(unsigned inputCount, unsigned hiddenNodeCount, unsigned outputCount, NodeClass nodeClass, bool zeroed = false);

    void setChromosome(const Chromosome &chromosome);
    Chromosome getChromosome() const;
    unsigned getChromosomeSize() const;

    virtual std::vector<float> io(const std::vector<float> &inputs);

protected:
    NodeLayer m_hiddenLayer;
    NodeLayer m_outputLayer;
};

#endif // __SINGLEMLP_HPP__
