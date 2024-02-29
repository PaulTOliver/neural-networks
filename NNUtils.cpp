#include "NNUtils.hpp"

std::default_random_engine rGenerator;

void seedRand()
{
    rGenerator.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

float realRand(float low, float hi)
{
    std::uniform_real_distribution<float> fDistributor(low, hi);
    return fDistributor(rGenerator);
}

int intRand(int low, int hi)
{
    std::uniform_int_distribution<int> iDistributor(low, hi - 1);
    return iDistributor(rGenerator);
}

float sigmoid(float input, float sensitivity)
{
    return 1.f / (1.f + expf(-input / sensitivity));
}

void crossover(const Chromosome &parent, const Chromosome &mother, Chromosome &child1, Chromosome &child2)
{
    if (parent.size() != mother.size())
    {
        return;
    }

    child1.clear();
    child2.clear();

    int cop = intRand(0, parent.size());

    child1.insert(child1.end(), parent.begin(), parent.begin() + cop);
    child1.insert(child1.end(), mother.begin() + cop, mother.end());
    child2.insert(child2.end(), mother.begin(), mother.begin() + cop);
    child2.insert(child2.end(), parent.begin() + cop, parent.end());
}

void mutate(Chromosome &chromosome, float mutationRate)
{
    for (auto &i : chromosome)
    {
        if (realRand(0.f, 1.f) < mutationRate)
        {
            i = realRand(-1.f, 1.f);
        }
    }
}
