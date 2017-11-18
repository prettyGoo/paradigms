from .abstract_transport import AbstractTransport


class Truck(AbstractTransport):
    id = 1

    def __init__(self, speed, power):
        self.speed = speed
        self.power = power

    def output_data(self):
        pass
