var assert = require('assert');
var solution087 = require('../src/euler/solution087');

describe('Solution087', function() {
  describe('answer', function() {
    it('will answer problem 087', function() {
      assert.equal(solution087.answer(), 1097343);
    });
  });
});