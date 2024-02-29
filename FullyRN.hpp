#ifndef __FULLYRN_HPP__
#define __FULLYRN_HPP__

#include "DualMLP.hpp"

class FullyRN : public DualMLP
{
public:
    FullyRN(unsigned inputCount, unsigned hiddenNodeCount, unsigned outputCount, NodeClass nodeClass, bool zeroed = false);

    std::vector<float> io(const std::vector<float> &inputs);

private:
    std::vector<float> m_context;
};

#endif // __FULLYRN_HPP__
