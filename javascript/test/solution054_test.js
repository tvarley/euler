var assert = require('assert');
var solution054 = require('../src/euler/solution054');

describe('Solution054', function() {
  describe('answer', function() {
    it('will answer problem 054', function() {
      assert.equal(solution054.answer(), 376);
    });
  });
});