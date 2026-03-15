var assert = require('assert');
var solution043 = require('../src/euler/solution043');

describe('Solution043', function() {
  describe('answer', function() {
    it('will answer problem 043', function() {
      assert.equal(solution043.answer(), 16695334890);
    });
  });
});