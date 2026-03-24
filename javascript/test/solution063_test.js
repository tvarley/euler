const assert = require('assert');
const solution = require('../src/euler/solution063');

describe('Solution 063', () => {
  it('should return the correct answer', () => {
    assert.equal(solution.answer(), 49);
  });
});