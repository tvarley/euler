const assert = require('assert');
const solution = require('../src/euler/solution062');

describe('Solution 062', () => {
  it('should return the correct answer', () => {
    assert.equal(solution.answer(), '127035954683');
  });
});