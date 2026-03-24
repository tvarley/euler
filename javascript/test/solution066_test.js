var assert = require('assert');
var solution066 = require('../src/euler/solution066');

describe('Solution066', function() {
  describe('answer', function() {
    it('will answer problem 066', function() {
      assert.equal(solution066.answer(), 661);
    });
  });
});