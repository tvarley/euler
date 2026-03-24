const assert = require('assert');
const solution = require('../src/euler/solution065');

describe('Solution 065', () => {
  it('should return the correct answer', () => {
    assert.equal(solution.answer(), 272);
  });
});