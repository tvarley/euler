var assert = require('assert');
var solution052 = require('../src/euler/solution052');

describe('Solution052', function() {
  describe('answer', function() {
    it('will answer problem 052', function() {
      assert.equal(solution052.answer(), 142857);
    });
  });
});