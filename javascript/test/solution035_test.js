var assert = require('assert');
var solution035 = require('../src/euler/solution035');

describe('Solution035', function() {
  describe('answer', function() {
    it('will answer problem 035', function() {
      assert.equal(solution035.answer(), 55);
    });
  });
});