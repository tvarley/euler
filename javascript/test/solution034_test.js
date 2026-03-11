var assert = require('assert');
var solution034 = require('../src/euler/solution034');

describe('Solution034', function() {
  describe('answer', function() {
    it('will answer problem 034', function() {
      assert.equal(solution034.answer(), 40730);
    });
  });
});