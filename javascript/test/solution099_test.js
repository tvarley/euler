var assert = require('assert');
var solution099 = require('../src/euler/solution099');

describe('Solution099', function() {
  describe('answer', function() {
    it('will answer problem 099', function() {
      assert.equal(solution099.answer(), 709);
    });
  });
});