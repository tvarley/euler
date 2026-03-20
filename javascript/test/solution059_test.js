var assert = require('assert');
var solution059 = require('../src/euler/solution059');

describe('Solution059', function() {
  describe('answer', function() {
    it('will answer problem 059', function() {
      assert.equal(solution059.answer(), 129448);
    });
  });
});
