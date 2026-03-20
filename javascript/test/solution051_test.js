var assert = require('assert');
var solution051 = require('../src/euler/solution051');

describe('Solution051', function() {
  describe('answer', function() {
    it('will answer problem 051', function() {
      assert.equal(solution051.answer(), 121313);
    });
  });
});