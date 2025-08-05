import sys

def viterbi(encoded_message):
    # (estado_actual, input): (estado_sig, output)
    transitions = {
        # Estado 00
        ('00', 0): ('00', '00'),
        ('00', 1): ('10', '11'),
        # Estado 01
        ('01', 0): ('00', '11'),
        ('01', 1): ('10', '00'),
        # Estado 10
        ('10', 0): ('01', '10'),
        ('10', 1): ('11', '01'),
        # Estado 11
        ('11', 0): ('01', '01'),
        ('11', 1): ('11', '10')
    }

    # estado inicial algoritmo de viterbi
    path_metrics = { # (métrica, camino)
        '00': (0, []),  
        '01': (float('inf'), []),
        '10': (float('inf'), []),
        '11': (float('inf'), [])
    }