var assert = require('assert');
var solution040 = require('../src/euler/solution040');

describe('Solution040', function() {
  describe('answer', function() {
    it('will answer problem 040', function() {
      assert.equal(solution040.answer(), 210);
    });
  });
});