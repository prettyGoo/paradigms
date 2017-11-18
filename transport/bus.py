from .abstract_transport import AbstractTransport


class Bus(AbstractTransport):
    id = 0

    def __init__(self, speed, power):
        self.speed = speed
        self.power = power

    def output_data(self):
        pass
