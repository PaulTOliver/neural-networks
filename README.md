Neural Network library used for the Guppies project. Parameters that can be set
by it follow:

## NETWORK STRUCTURE
Defines the main topology of the Neural Network (i.e. the way that Nodes
connect with each other). The four possible choices (in order of
complexity) are:

### Single MultiLayer Perceptron
A FeedForward network with 1 hidden layer. Information flows
unidirectionally from input nodes to output nodes (and not the
other way around).

### Dual MultiLayer Perceptron
Same as above, but with two hidden layers instead of one.

### Simple Recurrent Network (Elman Network)
This type of recurrent network has a set of "context" units that
store the output of the (single) hidden layer and feeds it back
to the input layer on the next time-step, giving it a kind of
short term memory.

### Fully Recurrent Network
All Nodes in this network are connected to each other. It's the
most complex (and processor intensive) network of the four.

## NODE STRUCTURE
Defines the structure of each network node. The two choices are:

### Neuron
Each neuron computes its outputs from a given set of inputs. Output
equals the weighted sum of all inputs.

### Memory Cell
This kind of node is based in the Long-Short Term Memory recurrent
network model. It contains 4 neurons, 3 of them act as "gates" that
allow it to block input, store it and output it, thus being able to
hold in information or "memories" for a long time span. It's the
most complex (and processor intensive) type of node.

## NODES PER HIDDEN LAYER
Number of nodes that reside on each hidden layer. SingleMLPs, SimpleRNs and
FullyRNs have one hidden layer. DualMLPs have two (thus, their number of
hidden nodes is "this value" x 2). The more nodes, the more complex the
Neural Networks of the Guppies are (and the more time it'll take to evolve
them).