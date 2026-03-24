const assert = require('assert');
const solution = require('../src/euler/solution061');

describe('Solution 061', () => {
  it('should return the correct answer', () => {
    assert.equal(solution.answer(), 28684);
  });
});