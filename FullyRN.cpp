#include "FullyRN.hpp"

FullyRN::FullyRN(unsigned inputCount, unsigned hiddenNodeCount, unsigned outputCount, NodeClass nodeClass, bool zeroed)
:   DualMLP(0, 0, 0, NEURON, true)
{
    unsigned contextSize = inputCount + hiddenNodeCount + outputCount;
    m_context.resize(contextSize, 0.f);

    m_firstHiddenLayer = NodeLayer(inputCount + contextSize, inputCount, nodeClass, zeroed);
    m_secondHiddenLayer = NodeLayer(contextSize, hiddenNodeCount, nodeClass, zeroed);
    m_outputLayer = NodeLayer(contextSize, outputCount, nodeClass, zeroed);

    m_inputCount = inputCount;
    m_hiddenNodeCount = hiddenNodeCount;
    m_outputCount = outputCount;
    m_nodeClass = nodeClass;
}

std::vector<float> FullyRN::io(const std::vector<float> &inputs)
{
    std::vector<float> response;

    if (inputs.size() != m_inputCount)
    {
        return response;
    }

    auto stateInput = inputs;
    stateInput.insert(stateInput.end(), m_context.begin(), m_context.end());
    response = m_firstHiddenLayer.io(stateInput);

    auto hiddenOutput = m_secondHiddenLayer.io(m_context);
    response.insert(response.end(), hiddenOutput.begin(), hiddenOutput.end());

    auto outputOutput = m_outputLayer.io(m_context);
    response.insert(response.end(), outputOutput.begin(), outputOutput.end());

    m_context = response;
    return outputOutput;
}
