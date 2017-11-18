from .abstract_transport import AbstractTransport


class Bus(AbstractTransport):
    id = 0

    def __init__(self, capacity, power):
        self.capacity = capacity
        super().__init__(power)

    def abstractionize(self):
        pass
