#ifndef __NNUTILS_HPP__
#define __NNUTILS_HPP__

#include <cmath>
#include <vector>
#include <random>
#include <chrono>
#include <memory>

enum NodeClass { NEURON, MEMORY_CELL };

enum NeuralNetClass { SINGLE_MLP, DUAL_MLP, SIMPLE_RN, FULLY_RN };

typedef std::vector<float> Chromosome;

void seedRand();

float realRand(float low, float hi);

int intRand(int low, int hi);

float sigmoid(float input, float sensitivity = 1.f);

void crossover(const Chromosome &parent, const Chromosome &mother, Chromosome &child1, Chromosome &child2);

void mutate(Chromosome &chromosome, float mutationRate = 0.001f);

#endif // __NNUTILS_HPP__
