var assert = require('assert');
var solution018 = require('../src/euler/solution018');

describe('Solution018', function() {
  describe('answer', function() {
    it('will answer problem 018', function() {
      assert.equal(solution018.answer(), 1074);
    });
  });
});