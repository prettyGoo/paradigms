from container.linked_list import LinkedList

from transport.bus import Bus
from transport.truck import Truck
from transport.decorators import SpeedDecorator, WeightToPowerBusDecorator, WeightToPowerTruckDecorator

from dataflow.io import IO

if __name__ == '__main__':

    container = LinkedList()
    io = IO(container, 'in', 'out')
    io.read()
    io.write()

    container.clean()

    print('Finished')