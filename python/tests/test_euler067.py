import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', 'src'))
from euler067 import solve

def test_solve():
    assert solve() == 7273