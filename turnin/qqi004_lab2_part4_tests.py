# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).

#Normal cases:
tests = [ {'description': 'PINA: 0x1E(30), PINB:0x1E(30), PINC:0x1E(30) => PORTB: 0x14',
    'steps': [ {'inputs': [('PINA',0x1E), ('PINB',0x1E), ('PINC',0x1E)], 'iterations': 5 } ], 
    'expected': [('PORTD',0x14)],
    },
#Total weight > 140kg, the difference between A and C does not exceeds 80 kg:
    {'description': 'PINA: 0x32(50), PINB:0x32(50), PINC:0x32(50) => PORTB: 0x25',
    'steps': [ {'inputs': [('PINA',0x32), ('PINB',0x32), ('PINC',0x32)], 'iterations': 5 } ], 
    'expected': [('PORTD',0x25)],
    },
#Total weight <=140kg, but the difference between A and C exceeds 80 kg:
    {'description': 'PINA: 0xA(10), PINB:0x14(20), PINC:0x65(101) => PORTB: 0x22',
    'steps': [ {'inputs': [('PINA',0xA), ('PINB',0x14), ('PINC',0x65)], 'iterations': 5 } ], 
    'expected': [('PORTD',0x22)],
    },
#Total weight > 140kg, the difference between A and C exceeds 80 kg:
    {'description': 'PINA: 0x14(20), PINB:0x1E(30), PINC:0x65(101) => PORTB: 0x27',
    'steps': [ {'inputs': [('PINA',0x14), ('PINB',0x1E), ('PINC',0x65)], 'iterations': 5 } ], 
    'expected': [('PORTD',0x27)],
    },
    ]
#watch = ['PORTB']

