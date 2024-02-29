#ifndef __SIMPLERN_HPP__
#define __SIMPLERN_HPP__

#include "SingleMLP.hpp"

class SimpleRN : public SingleMLP
{
public:
    SimpleRN(unsigned inputCount, unsigned hiddenNodeCount, unsigned outputCount, NodeClass nodeClass, bool zeroed = false);

    std::vector<float> io(const std::vector<float> &inputs);

private:
    std::vector<float> m_context;
};

#endif // __SIMPLERN_HPP__
