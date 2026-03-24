var assert = require('assert');
var solution070 = require('../src/euler/solution070');

describe('Solution070', function() {
  describe('answer', function() {
    it('will answer problem 070', function() {
      assert.equal(solution070.answer(), 8319823);
    });
  });
});