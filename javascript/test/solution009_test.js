var assert = require('assert');
var solution009 = require('../src/euler/solution009');

describe('Solution009', function() {
  describe('answer', function() {
    it('will answer problem 009', function() {
      assert.equal(solution009.answer(), 31875000);
    });
  });
});