from .abstract_transport import AbstractTransport


class Truck(AbstractTransport):
    id = 1

    def __init__(self, weight, power):
        self.weight = weight
        super().__init__(power)

    def abstractionize(self):
        pass

