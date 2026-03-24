import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', 'src'))
from euler070 import solve

def test_solve():
    assert solve() == 8319823