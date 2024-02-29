#ifndef __DUALMLP_HPP__
#define __DUALMLP_HPP__

#include "NeuralNet.hpp"

class DualMLP : public NeuralNet
{
public:
    DualMLP(unsigned inputCount, unsigned hiddenNodeCount, unsigned outputCount, NodeClass nodeClass, bool zeroed = false);

    void setChromosome(const Chromosome &chromosome);
    Chromosome getChromosome() const;
    unsigned getChromosomeSize() const;

    virtual std::vector<float> io(const std::vector<float> &inputs);

protected:
    NodeLayer m_firstHiddenLayer;
    NodeLayer m_secondHiddenLayer;
    NodeLayer m_outputLayer;
};

#endif // __DUALMLP_HPP__
