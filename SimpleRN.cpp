#include "SimpleRN.hpp"

SimpleRN::SimpleRN(unsigned inputCount, unsigned hiddenNodeCount, unsigned outputCount, NodeClass nodeClass, bool zeroed)
:   SingleMLP(0, 0, 0, NEURON, true)
{
    m_context.resize(hiddenNodeCount, 0.f);

    m_hiddenLayer = NodeLayer(inputCount + hiddenNodeCount, hiddenNodeCount, nodeClass, zeroed);
    m_outputLayer = NodeLayer(hiddenNodeCount, outputCount, nodeClass, zeroed);

    m_inputCount = inputCount;
    m_hiddenNodeCount = hiddenNodeCount;
    m_outputCount = outputCount;
    m_nodeClass = nodeClass;
}

std::vector<float> SimpleRN::io(const std::vector<float> &inputs)
{
    std::vector<float> response;

    if (inputs.size() != m_inputCount)
    {
        return response;
    }

    response.insert(response.end(), inputs.begin(), inputs.end());
    response.insert(response.end(), m_context.begin(), m_context.end());

    response = m_hiddenLayer.io(response);

    m_context = response;
    response = m_outputLayer.io(response);

    return response;
}
