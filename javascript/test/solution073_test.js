var assert = require('assert');
var solution073 = require('../src/euler/solution073');

describe('Solution073', function() {
  describe('answer', function() {
    it('will answer problem 073', function() {
      assert.equal(solution073.answer(), 7295372);
    });
  });
});