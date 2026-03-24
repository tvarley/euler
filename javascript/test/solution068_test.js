var assert = require('assert');
var solution068 = require('../src/euler/solution068');

describe('Solution068', function() {
  describe('answer', function() {
    it('will answer problem 068', function() {
      assert.equal(solution068.answer(), 6531031914842725);
    });
  });
});