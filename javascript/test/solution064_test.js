const assert = require('assert');
const solution = require('../src/euler/solution064');

describe('Solution 064', () => {
  it('should return the correct answer', () => {
    assert.equal(solution.answer(), 1322);
  });
});