import sys


class IO(object):
    def __init__(self, source, stdin_path, stdout_path):
        self.source = source
        self.stdin_path = stdin_path
        self.stdout_path = stdout_path

    def reset_stdin_path(self, new_path):
        self.stdin_path = new_path

    def reset_stdout_path(self, new_path):
        self.stdout_path = new_path
