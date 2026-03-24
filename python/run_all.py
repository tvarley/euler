#!/usr/bin/env python3
"""
Run all Project Euler solutions and print results.
"""
import sys
import os

# Add src to path
sys.path.insert(0, os.path.join(os.path.dirname(__file__), 'src'))

for i in range(1, 76):
    mod_name = f'euler{i:03d}'
    try:
        mod = __import__(mod_name)
        result = mod.solve()
        print(f"Problem {i}: {result}")
    except ImportError as e:
        print(f"Problem {i}: Error importing - {e}")
    except Exception as e:
        print(f"Problem {i}: Error - {e}")