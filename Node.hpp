#ifndef __NODE_HPP__
#define __NODE_HPP__

#include "NNUtils.hpp"

class Node
{
public:
    virtual void setChromosome(const Chromosome &chromosome) = 0;
    virtual Chromosome getChromosome() const = 0;
    virtual unsigned getChromosomeSize() const = 0;

    virtual float io(const std::vector<float> &inputs) = 0;

    unsigned getInputCount() const { return m_inputCount; }

protected:
    unsigned m_inputCount = 0;
};

#endif // __NODE_HPP__
