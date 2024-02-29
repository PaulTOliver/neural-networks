#include "NodeLayer.hpp"

NodeLayer::NodeLayer(unsigned inputCount, unsigned nodeCount, NodeClass nodeClass, bool zeroed)
:   m_inputCount(inputCount), m_nodeCount(nodeCount), m_nodeClass(nodeClass)
{
    if (nodeClass == NEURON)
    {
        while (nodeCount--)
        {
            m_nodes.push_back(std::unique_ptr<Node>(new Neuron(inputCount, zeroed)));
        }
    }
    else
    {
        while (nodeCount--)
        {
            m_nodes.push_back(std::unique_ptr<Node>(new MemCell(inputCount, zeroed)));
        }
    }
}

void NodeLayer::setChromosome(const Chromosome &chromosome)
{
    unsigned chrSize = getChromosomeSize();

    if (chrSize != chromosome.size())
    {
        return;
    }

    chrSize /= m_nodeCount;

    for (unsigned i = 0; i < m_nodeCount; ++i)
    {
        auto l1 = chromosome.begin() + i * chrSize;
        auto l2 = l1 + chrSize;
        Chromosome chrPart(l1, l2);
        m_nodes[i]->setChromosome(chrPart);
    }
}

Chromosome NodeLayer::getChromosome() const
{
    Chromosome chromosome;

    for (auto &i : m_nodes)
    {
        Chromosome chrPart = i->getChromosome();
        chromosome.insert(chromosome.end(), chrPart.begin(), chrPart.end());
    }

    return chromosome;
}

unsigned NodeLayer::getChromosomeSize() const
{
    return m_nodes.front()->getChromosomeSize() * m_nodeCount;
}

std::vector<float> NodeLayer::io(const std::vector<float> &inputs)
{
    std::vector<float> response;

    if (inputs.size() != m_inputCount)
    {
        return response;
    }

    for (auto &i : m_nodes)
    {
        response.push_back(i->io(inputs));
    }

    return response;
}
