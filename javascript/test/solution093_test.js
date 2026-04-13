var assert = require('assert');
var solution093 = require('../src/euler/solution093');

describe('Solution093', function() {
  describe('answer', function() {
    it('will answer problem 093', function() {
      assert.equal(solution093.answer(), 1258);
    });
  });
});