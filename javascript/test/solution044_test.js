var assert = require('assert');
var solution044 = require('../src/euler/solution044');

describe('Solution044', function() {
  describe('answer', function() {
    it('will answer problem 044', function() {
      assert.equal(solution044.answer(), 5482660);
    });
  });
});