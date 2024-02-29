#ifndef __NODELAYER_HPP__
#define __NODELAYER_HPP__

#include "Neuron.hpp"
#include "MemCell.hpp"

class NodeLayer
{
public:
    NodeLayer(unsigned inputCount, unsigned nodeCount, NodeClass nodeClass, bool zeroed = false);

    void setChromosome(const Chromosome &chromosome);
    Chromosome getChromosome() const;
    unsigned getChromosomeSize() const;

    std::vector<float> io(const std::vector<float> &inputs);

    unsigned getInputCount() const { return m_inputCount; }
    unsigned getNodeCount() const { return m_nodeCount; }
    NodeClass getNodeClass() const { return m_nodeClass; }

private:
    unsigned m_inputCount = 0;
    unsigned m_nodeCount = 0;
    NodeClass m_nodeClass;

    std::vector<std::unique_ptr<Node>> m_nodes;
};

#endif // __NODELAYER_HPP__
